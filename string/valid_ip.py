class Solution:
    def Ipv4(self, a):
        lst = a.split('.')

        if (len(lst) != 4):
            return "Neither"

        for part in lst:
            if not part or (part[0] == '0' and part != '0') or not part.isdigit() or int(part) > 255:
                return "Neither"

        return "IPv4"

    def Ipv6(self, a):
        lst = a.split(':')

        if len(lst) != 8:
            return "Neither"

        for part in lst:
            if not part or len(part) > 4:
                return "Neither"

        for ch in a:
            if ch.isalpha() and ch.lower() > 'f':
                return "Neither"

        return "IPv6"

    def validIPAddress(self, queryIP: str) -> str:
        if '.' in queryIP:
            return self.Ipv4(queryIP)

        if ':' in queryIP:
            return self.Ipv6(queryIP)

        return "Neither"
