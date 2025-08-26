//PROBLEM : 

      Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
      
      One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
      
      Implement the MyCircularQueue class:
      
      MyCircularQueue(k) Initializes the object with the size of the queue to be k.
      int Front() Gets the front item from the queue. If the queue is empty, return -1.
      int Rear() Gets the last item from the queue. If the queue is empty, return -1.
      boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
      boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
      boolean isEmpty() Checks whether the circular queue is empty or not.
      boolean isFull() Checks whether the circular queue is full or not.
      You must solve the problem without using the built-in queue data structure in your programming language. 



//APPROACH :
      keep track of, front, rear and the number of elements
          -> isFull = if number of element is k
          -> empty = if number of element is 0
          -> rear = if empty -1 else nums[rear]
          -> front = if empty -1 else nums[front]
          -> push = if count is equal to k push is not possible, else increment count and push the element in the rear end
          -> pop = if not mpty increment the first
      maintain the circular index by using % operator while push and pop



//CODE :
      class MyCircularQueue {
      public:
          vector<int> nums;
          int front = 0, rear = -1, count = 0;
          MyCircularQueue(int k) {
              nums.resize(k);
          }
          
          bool enQueue(int value) {
              if (isFull()) return false;
              rear = (rear + 1) % nums.size(); 
              nums[rear] = value;
              count++;
              return true;
          }
          
          bool deQueue() {
              if (isEmpty()) return false;
              front = (front + 1) % nums.size(); 
              count--;
              return true;
          }
          
          int Front() {
              if (isEmpty()) return -1;
              return nums[front];
          }
          
          int Rear() {
              if (isEmpty()) return -1;
              return nums[rear];
          }
          
          bool isEmpty() {
              return count == 0;
          }
          
          bool isFull() {
              return count == nums.size();
          }
      };
      
