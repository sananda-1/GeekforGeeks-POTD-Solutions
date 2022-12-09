
class Solution{
public:
    
    long long int numoffbt(long long int a[], int n){
        using ll = long long int ; 
        const ll N = 2e5 + 5 ; 
        vector<ll> fbt(N) ;
        const ll mod = 1e9 + 7 ; 
        
        for(int i = 0 ; i<n ; i++) fbt[a[i]] = 1 ; 
        ll ans = 0 ; 
        
        for(int i = 0 ; i<N ; i++){
            if(fbt[i] == 0) continue ; 
            ans = (ans + fbt[i]) % mod ; 
            for(int j = 2*i ; j<N ; j += i){
                if((fbt[j] == 0) || (j/i > i)) continue ;
                if(i != j/i)
                    fbt[j] = (fbt[j] + (2 * (fbt[i] * fbt[j/i]) % mod)%mod ) % mod ;
                else
                    fbt[j] = (fbt[j] + (fbt[i] * fbt[j/i]) % mod) % mod ;
            }
        }
        
        return ans ; 
    }
};