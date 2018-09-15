ans = 0
while True:
    try:
        s = input()
        if s == "":
            break
        s = int(s)
        if s == 0:
            print(ans)
            ans = 0
            continue
        ans += s
    except:
        break

