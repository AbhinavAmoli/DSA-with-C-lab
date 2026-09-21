#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int isopr(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int applyopr(int a, int b, char op) {
    if (op == '+') return b + a;
    if (op == '-') return b - a;
    if (op == '*') return b * a;
    return b / a;
}

int postfix(char exp[]) {
    int num = 0, read = 0;
    top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            read = 1;
        } else {
            if (read) {
                push(num);
                num = 0;
                read = 0;
            }

            if (isopr(c)) {
                int a = pop();
                int b = pop();
                push(applyopr(a, b, c));
            }
        }
    }

    return pop();
}

int main() {
    char exp[MAX];
    int t;

    scanf("%d", &t);
    getchar();

    while (t--) {
        fgets(exp, MAX, stdin);
        printf("%d\n", postfix(exp));
    }

    return 0;
}
