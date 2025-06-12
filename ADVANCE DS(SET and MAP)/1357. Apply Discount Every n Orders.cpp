//PROBLEM :

      There is a supermarket that is frequented by many customers. The products sold at the supermarket are represented as two parallel integer arrays 
        products and prices, where the ith product has an ID of products[i] and a price of prices[i].
      
      When a customer is paying, their bill is represented as two parallel integer arrays product and amount, where the jth product they purchased has 
        an ID of product[j], and amount[j] is how much of the product they bought. Their subtotal is calculated as the sum of 
        each amount[j] * (price of the jth product).
      
      The supermarket decided to have a sale. Every nth customer paying for their groceries will be given a percentage discount. The discount amount is
        given by discount, where they will be given discount percent off their subtotal. More formally, if their subtotal is bill, then they would actually 
        pay bill * ((100 - discount) / 100).
      
      Implement the Cashier class:
      
      Cashier(int n, int discount, int[] products, int[] prices) Initializes the object with n, the discount, and the products and their prices.
      double getBill(int[] product, int[] amount) Returns the final total of the bill with the discount applied (if any). 
        Answers within 10-5 of the actual value will be accepted.


//APPROACH :
      Simply store the product and its price in map and a number num which check which number of order is the nth order
      Provide discount for every nth order


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Cashier {
      public:
          unordered_map<int,int>mp;
          int num, dis, n1 = 0;;
          Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
              num = n;
              dis = discount;
              for(int i = 0;i < products.size(); i++) {
                  mp[products[i]] = prices[i];
              }
          }
          
          double getBill(vector<int> product, vector<int> amount) {
              n1 += 1;;
              n1 = n1%num;
              double total = 0;
              for(int i = 0;i < amount.size(); i++) {
                  total += amount[i]*mp[product[i]];
              }
              if(n1 == 0) {
                  return total*(((100-dis)*1.0)/100);
              }
              return total;
          }
      };
