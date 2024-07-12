t=int(input())
l=[]
for i in range(t):
    l.append(0)
lPairs=[]
for k in range(t):
    n=int(input())
    if(n in [1,2,3,4,5,7,10,11,13,14,16,18,20,21,24,35,68,90,94]):
        for a in range(10001):
            temp=a*str(n)
            for b in range(max(1,len(temp)-8),min(10001,len(temp))):
                if(str(a*n-b)==(a*str(n))[0:-b]):
                    l[k]+=1
                    lPairs.append([a,b])
    else:
        pass

s=0
for i in range(t):
    print(l[i])
    for j in range(s,s+l[i]):
        print(lPairs[j][0],lPairs[j][1])
    s+=l[i]
        



