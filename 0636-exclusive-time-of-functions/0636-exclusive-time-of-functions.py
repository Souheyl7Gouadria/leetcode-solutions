class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        st = []
        ans = [0]*n
        pre = 0
        for log in logs:
            i, op, t = log.split(":")
            i = int(i)
            cur = int(t)
            if op[0] == "s":
                if st:
                    ans[st[-1]] += cur-pre
                st.append(i)
                pre = cur
            else:
                ans[st.pop()] += cur-pre+1
                pre = cur+1
        return ans

        