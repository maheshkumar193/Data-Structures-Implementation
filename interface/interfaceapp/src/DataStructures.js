const dataStructures = [
    {
      name: "AVL Tree",
      imgURL: "https://static.javatpoint.com/ds/images/avl-tree.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/AVL.txt"
    },
    {
      name: "B Tree",
      imgURL:
        "data:image/png;base64,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",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/Btree.txt"
    },
    {
      name: "B+ Tree",
      imgURL: "https://upload.wikimedia.org/wikipedia/commons/3/37/Bplustree.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/B%2BTree.txt"
    },
    {
      name: "Circular Queue",
      imgURL:
        "https://static.packt-cdn.com/products/9781786463890/graphics/image_04_006.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/Circularqueue.txt"
    },
    {
      name: "LinkedList Stack",
      imgURL: "https://media.geeksforgeeks.org/wp-content/uploads/2-260.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/LinkedListstacks.txt"
    },
    {
      name: "Max Heap",
      imgURL:
        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQ1ApFLTfZ55sFJ4Eyi9RP3-xicrSCpJz6hBtnyLa6i293W8Wcm5aX1VaBrhloWg8yoXqJcG4NcVvuVxg&usqp=CAU",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/maxHeap.txt"
    },
    {
      name: "Min Heap",
      imgURL:
        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR7qMmXhwJ2bWtR67LNK7JvpQUQFbO-WVqCaXUDc8h2RhMZr7e6VE0Fi_OuLL_h0LN1GzmkL_2U02v96A&usqp=CAU",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/minHeap.txt"
    },
    {
      name: "Queue",
      imgURL:
        "https://cdn.journaldev.com/wp-content/uploads/2018/06/swift-queue-flow.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/queue.txt"
    },
    {
      name: "Red Black Tree",
      imgURL:
        "https://shunsvineyard.info/wp-content/uploads/2021/04/red_black_tree-theory.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/redBlackTree.txt"
    },
    {
      name: "stack",
      imgURL:
        "https://www.softwaretestinghelp.com/wp-content/qa/uploads/2019/06/pictorial-representation-of-stack.png",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/stacks.txt"
    },
    {
      name: "vector",
      imgURL:
        "https://data-flair.training/blogs/wp-content/uploads/sites/2/2019/07/Representation-fof-C-Vectors.jpg",
      codeLink:
        "https://github.com/maheshkumar193/Data-Structures-Implementation/blob/master/vector.txt"
    }
  ];
  
  export default dataStructures;
  