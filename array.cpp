/*

陣列是相同類型的物件序列，其佔用連續記憶體區域。 
傳統的 C 樣式數位是許多 Bug 的來源，但仍很常見，特別是在較舊的程式代碼基底中。 
在新式C++中，強烈建議使用 std::vector 或 std::array 。
這兩種標準連結庫類型都會將其元素儲存為連續的記憶體區塊。 
它們提供更大的類型安全性，並支持保證指向序列內有效位置的反覆運算器。

堆疊型數位的配置和存取速度比堆積型數位更快。 
不過，堆疊空間有限。 陣列元素的數目不能太大，因此會耗用太多堆疊記憶體

您可能需要在堆疊上配置太大的數位，或在編譯時期不知道其大小。 
您可以使用表達式，在堆積 new[] 上配置這個陣列。



*/


	int a[10];
    for (int i = 0; i < 10; ++i)
    {
        a[i] = i + 1;
    }
    int b[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	// Declare an array of doubles to be allocated on the heap
    double* numbers = new double[size]{ 0 };
    // Assign a new value to the first element
    numbers[0] = 1;
    // Assign a value to each subsequent element
    // (numbers[1] is the second element in the array.)
    for (size_t i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 1.1;
    }
	
/*

當陣列傳遞至函式時，它會當做第一個專案的指標傳遞，無論是堆疊型或堆積型陣列。 
指標不包含其他大小或類型資訊。
此行為稱為 指標衰變。 
當您將數位傳遞至函式時，必須一律在個別參數中指定元素數目。 
此行為也表示當數位傳遞至函式時，不會複製數位元素。 
若要防止函式修改專案，請將 參數指定為專案的指標 const 。

*/

void process(double *p, const size_t len)
{
    std::cout << "process:\n";
    for (size_t i = 0; i < len; ++i)
    {
        // do something with p[i]
    }
}

void process(const double *p, const size_t len);


//Static Integer Array
int a[5] = {1, 2, 3, 4, 5}; 
//Dynamic Integer Array
int *a = new int[5]; 

std::array<int, 5> arr1 = { 1, 2, 3, 4, 5 };



    // initialize
    Vector vector;
    VectorInit(&vector);

    printf("Initial - count: %d, limit: %d\n", vector.count, vector.limit);

    // add data
    vector.push_back(&vector, "Jin");
    vector.push_back(&vector, "Scorpion");
    vector.push_back(&vector, "Ryu");
    vector.push_back(&vector, "Akuma");
    vector.push_back(&vector, "Ken");
    vector.push_back(&vector, "Haohmaru");
    vector.push_back(&vector, "Heihachi");

	
	//initialize
	vector<int> v = {1, 5, 7, 4};
    // Removing 7 from vector v
    v.erase(find(v.begin(), v.end(), 7));
	for (auto i : v)
        cout << i << " ";
	
	
	/*
	
	Modifiers:

	assign
		Assign vector content (public member function)

	push_back
		Add element at the end (public member function)

	pop_back
		Delete last element (public member function)

	insert
		Insert elements (public member function)

	erase
		Erase elements (public member function)

	swap
		Swap content (public member function)

	clear
		Clear content (public member function)

	emplace
		Construct and insert element (public member function)

	emplace_back
		Construct and insert element at the end (public member function)
	
	
	
	
	*/

	
	