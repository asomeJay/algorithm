```python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        d = {}
        n = len(s)
        for i in range(n):
            c = s[i]
            if c in d:
                f = False
                d[c] = (d[c][0], i)
            else:
                d[c] = (i, -1)

        result = -1
        for k, v in d.items():
            f_t, s_t = v
            result = max(result, s_t - f_t - 1)

        return result
            
```