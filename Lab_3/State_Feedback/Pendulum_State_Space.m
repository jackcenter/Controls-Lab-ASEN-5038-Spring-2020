clear; clc; close all;
load("Pendelum_TF2.mat")

A = [0, 1; -a, -b];
B = [0, b]';
C = eye(2);

K = place(A,B, [-10, -20]);


G = [1, 0]';
