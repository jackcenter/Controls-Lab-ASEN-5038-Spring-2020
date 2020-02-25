clear; clc; close all;
load("Pendelum_TF2.mat")
load("Pendulum_SS_Init_Data")

A = [0, 1; -b, -a];
B = [0, c]';
C = eye(2);

K = place(A,B, [-16, -15]);

G = [1, 0]';

Ki = [10 0];


