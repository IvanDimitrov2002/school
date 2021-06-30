public class Calc{
    public static void main(String[] args){
        String expressionString = "";
        for(int i = 0; i < args.length; ++i){
            expressionString += args[i];
        }

        System.out.println(calculate(expressionString));
    }

    static Double calculate(String expr){
        String[] tokens = expr.split(" ");

        Double result = 0.0;
        String operator = "";

        for(int i = 0; i < tokens.length; ++i){
            try {
                Double num = Double.parseDouble(tokens[i]);
                switch(operator){
                    case "+":
                        result += num;
                        break;
                    case "-":
                        result -= num;
                        break;
                    case "*":
                        result *= num;
                        break;
                    case "/":
                        result /= num;
                        break;
                    default:
                        break;
                }
            } catch(NumberFormatException ex){
                operator = tokens[i];
            }
        }
        return result;
    }
}