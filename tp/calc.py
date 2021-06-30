class Calculator:

    def add(self,*args):
        self.add_result = sum(args)
        return self.add_result

    def multiply(self,*args):
        self.multiply_result=1
        for i in args:
            self.multiply_result*=i  
        return self.multiply_result
    
    def divide(self,*args):
        self.divide_result=args[0]
        for i in args[1:]:
            self.divide_result/=i
        return self.divide_result;

    def sub(self,*args):
        self.sub_result=args[0]
        for i in args[1:]:
            self.sub_result-=i
        return self.sub_result

calc = Calculator()
print(calc.divide(18,9))
