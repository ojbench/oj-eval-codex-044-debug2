#include <bits/stdc++.h>
using namespace std;

class mystring {
private:
    char *ch = nullptr;
    int len = 0;

    static char *alloc_and_copy(const char *src, int n) {
        if (n <= 0) return nullptr;
        char *p = new char[n];
        for (int i = 0; i < n; ++i) p[i] = src[i];
        return p;
    }

public:
    mystring() = default;

    mystring(int _len, int c) {
        if (_len > 0) {
            len = _len;
            ch = new char[len];
            char cc = static_cast<char>(c);
            for (int i = 0; i < len; ++i) ch[i] = cc;
        }
    }

    mystring(const string &c) {
        len = static_cast<int>(c.length());
        if (len > 0) {
            ch = new char[len];
            for (int i = 0; i < len; ++i) ch[i] = c[i];
        }
    }
    mystring(string &c) : mystring(static_cast<const string &>(c)) {}

    mystring(const mystring &o) {
        len = o.len;
        ch = alloc_and_copy(o.ch, len);
    }

    mystring(mystring &&o) noexcept {
        ch = o.ch;
        len = o.len;
        o.ch = nullptr;
        o.len = 0;
    }

    mystring &operator=(const mystring &o) {
        if (this == &o) return *this;
        char *newch = alloc_and_copy(o.ch, o.len);
        delete[] ch;
        ch = newch;
        len = o.len;
        return *this;
    }

    mystring &operator=(mystring &&o) noexcept {
        if (this == &o) return *this;
        delete[] ch;
        ch = o.ch;
        len = o.len;
        o.ch = nullptr;
        o.len = 0;
        return *this;
    }

    ~mystring() {
        delete[] ch;
        ch = nullptr;
        len = 0;
    }

    int get_len() const { return len; }

    char operator[](int x) const {
        if (x < 0 || x >= len) return '\0';
        return ch[x];
    }

    bool operator<(const mystring &rhs) const {
        int n = min(len, rhs.len);
        for (int i = 0; i < n; ++i) {
            if (ch[i] != rhs.ch[i]) return ch[i] < rhs.ch[i];
        }
        return len < rhs.len;
    }

    void ADD(const mystring &other) {
        if (other.len == 0) return;
        int newlen = len + other.len;
        char *p = new char[newlen];
        for (int i = 0; i < len; ++i) p[i] = ch[i];
        for (int i = 0; i < other.len; ++i) p[len + i] = other.ch[i];
        delete[] ch;
        ch = p;
        len = newlen;
    }

    void out() const {
        for (int i = 0; i < len; ++i) putchar(ch ? ch[i] : '\0');
    }

    friend ostream &operator<<(ostream &os, const mystring &s) {
        for (int i = 0; i < s.len; ++i) os << s.ch[i];
        return os;
    }
};

string str_in1, str_in2;
int n, id;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> id)) return 0;
    if (id == 1) {
        mystring str1(100, 'a');
        str1.out(); puts("");
        // cout << str1 << endl;
    } else if (id == 2) {
        cin >> str_in1;
        mystring str2 = str_in1;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str2[x] << '\n';
        }
    } else if (id == 3) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cout << (int)(str2 < str3) << '\n';
    } else if (id == 4) {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    } else {
        cin >> str_in1 >> str_in2;
        mystring str2 = str_in1;
        mystring str3 = str_in2;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << str3[x] << '\n';
        }
        cout << (int)(str2 < str3) << '\n';
        str2.ADD(str3);
        str2.out(); puts("");
        // cout << str2 << endl;
    }
    return 0;
}
