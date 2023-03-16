class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        self.max_distro = inf
        cookies.sort(reverse=True)

        def backtrack(distro: List[int], index : int):

            if index == len(cookies):
                self.max_distro = min(self.max_distro, max(distro))
                return

            if max(distro) >= self.max_distro:
                return

            for i in range(k):
                distro[i] += cookies[index]
                backtrack(distro, index + 1)
                distro[i] -= cookies[index]

        backtrack([0]*k, 0)
        return self.max_distro
