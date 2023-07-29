[eigs,eigsT] = readComplexFile("out_p64.txt");

plot(eigs,'o');
hold on
plot(eigs,'*');
legend("Original","Transposed");
title("GRCAR Size="+(size(eigs,1)));