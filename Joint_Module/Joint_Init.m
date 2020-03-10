clear; clc; close all;

% Initializing QuarcBlock

%Input Signal
    A = 1/5;                             %Amplitude
    T = 40;                            %Experiment Time
    dT = 0.002;                          %Sampling Time
    f = 2*pi/T;                         %Frequency
    F = 0:2*pi/T:2*pi/dT-2*pi/T;        %Frequency Vector
    Max = 200 * T/(2*pi);
    t_sample = 0.002;
    
    save('Joint_Init_Data', 'T', 'dT', 'F')
    