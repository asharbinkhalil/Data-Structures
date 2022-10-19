def bruteforce(str,pat):
    count=0
    for i in  range(0,len(str)):
        for j in range(0,len(pat)):
            if pat[j]==str[i]:
                j=j+1
                if j==len(pat):
                    count=count+1
            else:
                j=0

    print(count)


if __name__ == "__main__":
    bruteforce("helloathellhellohellohell","hello")