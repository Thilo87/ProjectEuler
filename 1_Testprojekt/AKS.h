bool isPseudoPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    if (n < 9) return true;
    if (n % 3 == 0) return false;
    if (n % 5 == 0) return false;

	int ar[] = { 2, 3 } ;
    for (int i = 0; i < ar.Length; i++) {
        if (Witness(ar[i], n)) return false;
    }
    return true;
}


bool Witness(int a, int n) {
    int t = 0;
    int u = n - 1;
    while ((u & 1) == 0) {
        t++;
        u >>= 1;
    }
         
    long xi1 = ModularExp(a, u, n);
    long xi2;

    for (int i = 0; i < t; i++) {
        xi2 = xi1 * xi1 % n;                
        if ((xi2 == 1) && (xi1 != 1) && (xi1 != (n - 1))) return true;
        xi1 = xi2;
    }
    if (xi1 != 1) return true;
    return false;
}


long ModularExp(int a, int b, int n) {
    long d = 1;
    int k = 0;
    while ((b >> k) > 0) k++;

    for (int i = k - 1; i >= 0; i--) {
        d = d * d % n;
        if (((b >> i) & 1) > 0) d = d * a % n;
    }

    return d;
}