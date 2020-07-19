# [题目](https://leetcode.com/problems/simplify-path/)

* Simplify Path
> Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

> In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

> Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

* Example 1:

> Input: "/home/"

> Output: "/home"

> Explanation: Note that there is no trailing slash after the last directory name.

* Example 2:

> Input: "/../"

> Output: "/"

> Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

* Example 3:

> Input: "/home//foo/"

> Output: "/home/foo"

> Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

* Example 4:

> Input: "/a/./b/../../c/"

> Output: "/c"

* Example 5:

> Input: "/a/../../b/../c//.//"

> Output: "/c"

* Example 6:

> Input: "/a//b////c/d//././/.."

> Output: "/a/b/c"

# 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        istringstream ss(path);
        string item;
        while (getline(ss, item, '/')){
            // 若是 ".." ，则把上一层目录干掉
            if (item == ".."){
                if (!st.empty()){
                    st.pop();
                }
            }
            else if (item != "." && item != ""){
                // "." 和 "" 不加进来
                st.push(item);
            }
        }

        if (st.empty()) return "/";

        string res = "";
        while (!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        return res;
    }
};
```

# 思路

* 栈，遇到 ".." 时，把刚进入栈的上级目录弹出

* 字符串分割
