#include<cstdio>
#include<map>
using namespace std;

int main(){
    long T; scanf("%d", &T);
    map<char, int> m;
    for(int t = 0; t<T; t++){
        int K; scanf("%d", &K);
        m.clear();
        int price;
        char c;
        for(int k = 0; k<K; k++){
            getchar(); c = getchar();
            scanf("%d", &price);
            m[c] = price;
            
        }
        int M; scanf("%d", &M);
        c = getchar();
        long count = 0;
        while((c = getchar())!=EOF)
            if(c!=' ' || c!='\n') count += m[c];
        printf("%0.2f$\n", count/100.0);
    }
    return 0;
}
