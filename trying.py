t=int(input())
l=[]
for i in range(t):
    l.append(0)
lPairs=[]
for k in range(2,t):
    n=k
    for a in range(10001):
        
        temp=a*str(n)
        for b in range(max(1,len(temp)-8),min(10001,len(temp))):
            
            if(str(a*n-b)==(a*str(n))[0:-b]):
                print(n)