[eigs_d,eigsT_d] = readComplexFile("out100_double.txt");
[eigs_p32,eigsT_p32] = readComplexFile("out100_p32.txt");
[eigs_p64,eigsT_p64] = readComplexFile("out100_p64.txt");

plot(eigs_d,'o');
hold on
plot(eigsT_d,'*');
plot(eigs_p32,'+');
plot(eigsT_p32,'square');
legend("Double","DoubleT","P32","P32T");
title("GRCAR Size="+(size(eigs_d,1)));