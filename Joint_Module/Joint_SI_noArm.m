clc; clear; close all;
load('Joint_SI_CL_40s_noarm_Data.mat')
load('Joint_Init_Data.mat')

% FFT of input and ouput 
R = fft(r);
Th = fft(Theta);

index = find(F<200 * T/(2*pi)); 
% index = find(abs(R/length(R)) >= 9e-2); 
B = 0*R;                     
B(index) = Th(index)./(R(index)+ Th(index));         %System Response 
B(index) = abs(B(index));               %Magnitude of System Response
B_log = 20*log10(B);

K = mean(B_log(2:5));
K_3dB = K - 3;

Index_id1 = find(B_log(2:end) < K_3dB);
Index_id1 = Index_id1(1);
omega1 = F(Index_id1);
omega2 = 33;

figure
semilogx(F, B_log)
hold on

s = tf('s');
H = db2mag(K)/((s/omega1 + 1)*(s/omega2 + 1));
bodemag(H)

% TODO: figure out why numerator and last denominator are not the same