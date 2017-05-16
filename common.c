int gcd(int m, int n)
{
    int r;

    r = m % n;
    while (r){
        m = n;
        n = r;
        r = m % n;
    }

    return n;
}
