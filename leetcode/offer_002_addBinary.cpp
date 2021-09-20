class Solution {
public:
    string addBinary(string a, string b) {
        int tmp = 0;
        int a_length = a.size();
        int b_length = b.size();
        string result;
        int longer_length = a_length > b_length ? a_length : b_length;
        int i = 1;

        while ((a_length - i) >= 0 && (b_length -i) >= 0) {
            if ((a[a_length - i] - 48 + b[b_length - i] - 48 + tmp) > 2) {
                printf("ca 1 %d\n",a[a_length - i]);
                result.insert(0, "1");
                tmp = 1;
            } else if ((a[a_length - i] - 48 + b[b_length - i] - 48 + tmp) > 1) {
                printf("ca 0\n");
                result.insert(0, "0");
                tmp = 1;
            } else {
                printf("ca  %d  %d %d\n", a[a_length - i] - 48 , b[b_length - i] - 48, a[a_length - i] - 48 + b[b_length - i] - 48 + tmp);
                result.insert(0, to_string(a[a_length - i] - 48 + b[b_length - i] - 48 + tmp));
                tmp = 0;
            }

            printf(" cur %s\n", result.c_str());
            ++i;
        }

        while (a_length - i >= 0) {
            if ((a[a_length - i] - 48 + tmp) > 2) {
                result.insert(0, "1");
                tmp = 1;
            } else if ((a[a_length - i] - 48 + tmp) > 1) {
                result.insert(0, "0");
                tmp = 1;
            } else {
                result.insert(0, to_string(a[a_length - i] - 48 + tmp));
                tmp =0;
            }
            ++i;
        }

        while (b_length - i >= 0) {
            if ((b[b_length - i] - 48 + tmp) > 2) {
                result.insert(0, "1");
                tmp = 1;
            } else if ((b[b_length - i] - 48 + tmp) > 1) {
                result.insert(0, "0");
            } else {
                result.insert(0, to_string(b[b_length - i] - 48 + tmp));
                tmp =0;
            }
            ++i;
        }
        printf("%s\n", result.c_str());

        if (tmp) {
            printf("tmp 1\n" );
            result.insert(0, "1");
        }
        return result;
    }
};
