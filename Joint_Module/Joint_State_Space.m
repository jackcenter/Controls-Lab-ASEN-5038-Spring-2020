%% State Space
% x = [theta, theta_dot, alpha, alpha_dot]

A = [0, 1, 0, 0;
     0, -a, -b, -c;
     0, 0, 0, 1;
     0, a, -c-d, -c-e];
B = [0, f, 0, -f];
C = [1, 0, 0, 0;
     0, 0, 1, 0];
D = zeros(2,1);

sys = ss(A,B,C,D);

G = [1, 0, 0, 0];
%% LQR

Q = [1, 0, 0, 0; 
     0, 0.01, 0, 0;
     0, 0, 1, 0;
     0, 0, 0, 1];
 
r = 0.01;
R = r*eye(2);

K = lqr(sys, Q, R);
eigs(A-B*K);

%% LQI

Q = blkdiag(Q,.1);
r = .01;
R = r*eye(1);

[K_joint, ~, lambdas] = lqi(sys, Q, R);
K = K_joint(1:2);
Ki = -K_joint(3);
