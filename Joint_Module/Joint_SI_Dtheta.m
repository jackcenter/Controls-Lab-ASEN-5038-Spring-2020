clear; clc; close all;

load('Joint_SI_CL_40s_dtheta_Data.mat')
load('Joint_Init_Data.mat')

R = fft(r);
dTheta_tf = fft(Theta);

index1 = find(F<200 * T/(2*pi)); 
% index1 = find(abs(R/length(R)) >= 9e-2);
G = 0*dTheta_tf;
G(index1) = dTheta_tf(index1)./R(index1);
G(index1) = abs(G(index1));
G_log = 20*log10(G);

K = mean(G_log(3:15));
K_3dB = K - 3;

figure
semilogx(F, G_log, 'k')
hold on