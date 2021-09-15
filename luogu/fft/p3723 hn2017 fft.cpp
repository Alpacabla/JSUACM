#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=4e5+5;
const double PI = acos(-1.0);
struct Complex
{
    double x, y;
    Complex(double _x = 0.0, double _y = 0.0)
    {
        x = _x;
        y = _y;
    }
    Complex operator-(const Complex &b) const
    {
        return Complex(x - b.x, y - b.y);
    }
    Complex operator+(const Complex &b) const
    {
        return Complex(x + b.x, y + b.y);
    }
    Complex operator*(const Complex &b) const
    {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};
/*
 * 进行 FFT 和 IFFT 前的反置变换
 * 位置 i 和 i 的二进制反转后的位置互换
 *len 必须为 2 的幂
 */
void change(Complex y[], int len)
{
    int i, j, k;
    for (int i = 1, j = len / 2; i < len - 1; i++)
    {
        if (i < j)
            swap(y[i], y[j]);
        // 交换互为小标反转的元素，i<j 保证交换一次
        // i 做正常的 + 1，j 做反转类型的 + 1，始终保持 i 和 j 是反转的
        k = len / 2;
        while (j >= k)
        {
            j = j - k;
            k = k / 2;
        }
        if (j < k)
            j += k;
    }
}
/*
 * 做 FFT
 *len 必须是 2^k 形式
 *on == 1 时是 DFT，on == -1 时是 IDFT
 */
void fft(Complex y[], int len, int on)
{
    change(y, len);
    for (int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
        for (int j = 0; j < len; j += h)
        {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; k++)
            {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (on == -1)
    {
        for (int i = 0; i < len; i++)
        {
            y[i].x /= len;
        }
    }
}
Complex x1[max_n],x2[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n<<1),b(n),d(n);
	ll sum=0;
	ll dd=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i]*a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		d[i]=a[i]-b[i];
		sum+=b[i]*b[i];
		dd+=d[i];
	}
	for(int i=n;i<(n<<1);i++){
		a[i]=a[i-n];
	}
	reverse(b.begin(),b.end());
	int lenlen=n*3;
	int len=1;
	while(len<lenlen) len<<=1;
	for(int i=0;i<(n<<1);i++) x1[i]=Complex(a[i],0);
	for(int i=(n<<1);i<len;i++) x1[i]=Complex(0,0);
	for(int i=0;i<(n);i++) x2[i]=Complex(b[i],0);
	for(int i=n;i<len;i++) x2[i]=Complex(0,0);
	fft(x1,len,1),fft(x2,len,1);
	for(int i=0;i<len;i++) x1[i]=x1[i]*x2[i];
	fft(x1,len,-1);
	ll ans=-ll_inf;
	for(int i=n-1;i<(n<<1);i++){
		ans=max(ans,ll(x1[i].x+0.5));
	}
	ans*=-2;
	ll out=ll_inf;
	for(int i=0;i<=1000;i++){
		out=min(out,2*i*dd+1ll*i*i*n+ans);
		out=min(out,2*i*(-dd)+1ll*i*i*n+ans);
	}
	cout<<out+sum<<endl;
	return 0;
}