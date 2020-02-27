clear; clc; close all;
load("Pendelum_TF2.mat")
load("Pendulum_SS_Init_Data")

A = [0, 1; -b, -a];
B = [0, c]';
C_lqi = [1 0];
D_lqi = 0;

K = place(A,B, [-14, -13]);   % State feedback 
eigs(A-B*K)

G = [1, 0]';
Ki = [10 0];

%% LQR

% Q = eye(2)
Q = [1 0; 0 0.01];
r = 0.01;
R = r*eye(1);

K = lqr(A, B, Q, R);
eigs(A-B*K);

%% LQI
sys = ss(A,B,C_lqi,D_lqi);
Q_new = blkdiag(Q,.1);
r = .01;
R = r*eye(1);

[K_joint, ~, lambdas] = lqi(sys, Q_new, R);
K = K_joint(1:2)
Ki = -K_joint(3)
lambdas

%% Sin Tracking ?
a = 1;
omega = 1;
phi = 0;

