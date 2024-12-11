//dawg just put this and come:
float calculate(float x, char op, float y)
{
    switch(op)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '*':
            return x*y;
        case '/':
            if(y!=0)
                return x/y;
            else
            {
                printf("cant divide by zero da");
                exit(1);
            }
        default:
            printf("Invalid operator");
            exit(1);
    }
}


float eval(NODE *bst){
    if(bst->isOper==0)
    {
        return bst->operand;
    }
    float x=eval(bst->left);
    float y=eval(bst->right);
    return calculate(x,bst->operator,y);
}
