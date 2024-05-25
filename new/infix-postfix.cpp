#include <iostream>
#include <stack>

using namespace std;

bool isOperatorStronger(string a, string b)
{
    if (a == "(" || a == ")")
    {
        if (b == "*" || b == "x" || b == "/" || b == ":" || b == "+" || b == "-" || b == "")
        {
            return true;
        }
    }
    if (a == "*" || a == "x" || a == "/" || a == ":")
    {
        if (b == "+" || b == "-" || b == "")
        {
            return true;
        }
    }
    if (a == "+" || a == "-")
    {
        if (b == "")
        {
            return true;
        }
    }
    return false;
}

void displayStack(stack<string> stack)
{
    string disp = "";
    while (!stack.empty())
    {
        disp = stack.top() + " " + disp;
        stack.pop();
    }
    cout << disp << endl;
}

stack<string> convertToPostFix(string input)
{
    stack<string> stackTemp;
    stack<string> stackHasil;

    string operand = "";
    stack<string> stackKurung;
    bool kurungAktif = false;
    for (int i = 0; i < static_cast<int>(input.length()); i++)
    {
        if (isdigit(input[i]))
        {
            // tambahin ke buffer variabel operand, ini untuk scan operand.
            // hanya sahkan operand ketika sudah scan operator nantinya
            operand = operand + input[i];
        }
        else
        {
            string op = string(1, input[i]);

            // ------------------
            // Handle Operand
            // ------------------

            // kalau ada operand, langsung taruh ke stack hasil.
            // reset operand buffer
            if (operand != "")
            {
                stackHasil.push(operand);
                operand = "";
            }

            // ------------------
            // Handle Kurung
            // ------------------

            // kalau ada kurung buka, kita catet operatornya di stackKurung
            if (op == "(")
            {
                kurungAktif = true;
                continue;
            }

            // ini proses nyatet operator didalam kurung
            if (kurungAktif && op != "(" && op != ")")
            {
                string lastOp = "";
                if (!stackKurung.empty())
                {
                    lastOp = stackKurung.top();
                }
                // selagi di stack kurung masih ada operator yg lebih kuat
                // keluarin semuanya dari situ dipindah ke stack hasil
                while (!isOperatorStronger(op, lastOp))
                {
                    if (!stackKurung.empty())
                    {
                        stackKurung.pop();
                    }
                    stackHasil.push(lastOp);
                    lastOp = "";
                    if (!stackKurung.empty())
                    {
                        lastOp = stackKurung.top();
                    }
                }
                stackKurung.push(op);
                continue;
            }

            // kalau ada kurung yang ketutup itu artinya kita gaperlu nyatet operator lagi,
            // operator didalam kurung yang kita catet dipindah ke stack hasil
            if (op == ")")
            {
                kurungAktif = false;
                while (!stackKurung.empty())
                {
                    stackHasil.push(stackKurung.top());
                    stackKurung.pop();
                }
                continue;
            }

            // ------------------
            // Handle Operator +, -, *, /
            // ------------------

            // kalau operator yang mau ditaruh sama dengan atau lebih lemah,
            // operator sebelumnya (jika ada), dipindah ke stack hasil

            // ngambil operator sebelumnya di stack sementara
            string lastOp = "";
            if (!stackTemp.empty())
            {
                lastOp = stackTemp.top();
            }

            // selagi di stack sementara masih ada operator yang lebih kuat
            // keluarin semuanya dari situ dipindah ke stack hasil
            while (!isOperatorStronger(op, lastOp))
            {
                if (!stackTemp.empty())
                {
                    stackTemp.pop();
                }
                stackHasil.push(lastOp);
                lastOp = "";
                if (!stackTemp.empty())
                {
                    lastOp = stackTemp.top();
                }
            }
            stackTemp.push(op);
        }
    }

    // cek variable operand,  kalau ada taruh di stack hasil
    if (operand != "")
    {
        stackHasil.push(operand);
    }

    // ketika udah kelar semuanya. pindahin sisa-sisa stack sementara ke stack ahsil
    while (!stackTemp.empty())
    {
        string op = stackTemp.top();
        stackHasil.push(op);
        stackTemp.pop();
    }
    return stackHasil;
}

stack<string> revertStack(stack<string> input)
{
    stack<string> res;

    while (!input.empty())
    {
        res.push(input.top());
        input.pop();
    }
    return res;
}

int calculatePostFix(stack<string> postFixStack)
{
    stack<string> postFix = revertStack(postFixStack);

    stack<string> exec;
    while (!postFix.empty())
    {
        exec.push(postFix.top());
        postFix.pop();

        if (!isdigit(exec.top()[0]))
        {
            string op = exec.top();
            exec.pop();
            string a = exec.top();
            exec.pop();
            string b = exec.top();
            exec.pop();

            int res;
            if (op == "+")
            {
                res = atoi(b.c_str()) + atoi(a.c_str());
            }
            else if (op == "-")
            {
                res = atoi(b.c_str()) - atoi(a.c_str());
            }
            else if (op == "*")
            {
                res = atoi(b.c_str()) * atoi(a.c_str());
            }
            else if (op == "/")
            {
                res = atoi(b.c_str()) / atoi(a.c_str());
            }
            exec.push(to_string(res));
        }
    }
    return atoi(exec.top().c_str());
}

int main()
{
    // ------------------------------------------------
    // menerima input (infix)
    // sample: 12*5+7-(23+2)/5-4
    // sample: 12*5+(25-2*10)/5-(2/2+1) = 59
    // ------------------------------------------------
    string input;
    cin >> input;

    // ------------------------------------------------
    // step 1: Konversi dari inputan (infix) ke postfix
    // ------------------------------------------------
    stack<string> postFix = convertToPostFix(input);
    // cout << "postfix: " << endl;
    // displayStack(postFix);

    int num = calculatePostFix(postFix);
    // cout << "hasil: " << num;
    cout << num;
    return 0;
}
