clc; close all;
load('Joint_SI_CL_Data.mat')
load('Joint_Init_Data.mat')

% FFT of input and ouput 
U = fft(u);
Y = fft(Theta);

index0 = find(abs(U/length(U)) >= 9e-2); 
B = 0*U;                     
B(index0) = Y(index0)./(U(index0)+ Y(index0));         %System Response 
B(index0) = abs(B(index0));               %Magnitude of System Response
B_log = 20*log10(B);
        
figure()
semilogx(F,B_log,'r')
hold on

K = mean(B_log(2:4));
K_3dB = K - 3;
% Index_tau = find(B_log(2:end) < K_3dB);
% Index_tau = Index_tau(1)+1;
% omega1 = F(Index_tau);
% omega2 = 10.5;
%% Transfer Function Theta/Alpha
Theta = Y;
Alpha = fft(Alpha);

% index1 = find(abs(Alpha/length(Alpha)) >= 9e-2); 
index1 = 1:length(Alpha);
B = 0*Alpha;
B(index1) = Theta(index1)./(Alpha(index1) + Theta(index1));
B(index1) = abs(B(index1));
B_log = 20*log10(B);

figure
semilogx(F, B_log, 'k')

%% First Order Transfer Function
% s = tf('s');
% H1 =  db2mag(K) / (s/omega1 + 1);
% [mag ph wout] = bode(H1);
% Mag = reshape(mag,[],size(mag,2),1);
% Mag = mag2db(Mag);
% plot(wout, Mag)
% grid on 
% H2 = db2mag(K) / ((s/omega2 + 1)*(s/omega1 + 1));
% bodemag(H2)