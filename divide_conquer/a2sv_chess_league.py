import sys

I = sys.stdin.readline
P = sys.stdout.write


def main():
    n, k = list(map(int, I().strip().split()))
    ratings = list(map(int, I().strip().split()))

    def solve(l, r):
        if r - l == 1:
            return [l]

        mid = l + (r - l) // 2
        left = solve(l, mid)
        right = solve(mid, r)

        left.sort(key=lambda x: ratings[x])
        right.sort(key=lambda x: ratings[x])

        i = j = 0
        while (i < len(left) and j < len(right)):
            diff = ratings[left[i]] - ratings[right[j]]
            if abs(diff) <= k:
                break
            elif diff < 0:
                i += 1
            else:
                j += 1

        return left[i:] + right[j:]

    winners = solve(0, 2 ** n)
    winners.sort()
    winners = [str(r + 1) for r in winners]
    print(" ".join(winners))

if __name__ == "__main__":
    main()
