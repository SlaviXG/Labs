#include "App.h"

using std::cin;
using std::cout;
using std::endl;

void App::DemoMode()
{
    bool correct_input = false;
    int array_size = 0;

    do
    {
        //Entering the size
        cout << "Enter the size of array :" << endl;
        cin >> array_size;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Processing input :
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            correct_input = true;
        cout << endl;
    } while (!correct_input);

    Point array[4][array_size];

    for(int i = 0; i < array_size; i++)
        array[0][i].getRandomValue();

    for(int j = 1; j < 4; j++)
    {
        for(int i = 0; i < array_size; i++)
        {
            array[j][i] = array[0][i];
        }
    }

    cout << "Array :" << endl;
    printArray(array[0], array_size);
    cout << "------\n" << endl << endl;

    cout << "Insertion Sort :" << endl;
    insertionSort(array[0], array_size, true);
    cout << "------\n" << endl;

    cout << "QuickSort :" << endl;
    quickSort(array[1],0,array_size-1, array_size, true);
    cout << "------\n" << endl;


    cout << "Merge Sort :" << endl;
    mergeSort(array[2],0,array_size-1, array_size, true);
    cout << "------\n" << endl;

    cout << "Combined :" << endl;
    combinedSort(array[3],0,array_size-1, 10, array_size, true);
    cout << "------\n" << endl;
}

void App::BenchmarkMode()
{
    Timer timer;
    bool correct_input = false;
    int array_size = 0;
    long double result[4];
    std::ofstream fout;

    do
    {
        //Entering the size
        cout << "Enter the size of array :" << endl;
        cin >> array_size;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Processing input :
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            correct_input = true;
        cout << endl;
    } while (!correct_input);

    Point array[4][array_size];

    for(int i = 0; i < array_size; i++)
        array[0][i].getRandomValue();

    for(int j = 1; j < 4; j++)
        for(int i = 0; i < array_size; i++)
            array[j][i] = array[0][i];

    std::cerr << "Testing..." << endl;

    timer.reset();
    insertionSort(array[0], array_size, false);
    result[0] = timer.elapsed();

    timer.reset();
    quickSort(array[1],0,array_size-1, array_size, false);
    result[1] = timer.elapsed();

    timer.reset();
    mergeSort(array[2],0,array_size-1, array_size, false);
    result[2] = timer.elapsed();

    timer.reset();
    combinedSort(array[3],0,array_size-1, 10, array_size, false);
    result[3] = timer.elapsed();

    fout.open("benchmark.txt");
    if(fout.is_open())
    {
        fout << "N = " << array_size << "\n\n";

        fout << "Insertion : \n"
                "--------------------------------------------------------------------------\n";
        fout << result[0] << " ms\n";
        fout << "--------------------------------------------------------------------------\n";
        fout << "Quick : \n"
                "--------------------------------------------------------------------------\n";
        fout << result[1] << " ms\n";
        fout << "--------------------------------------------------------------------------\n";
        fout << "Merge : \n"
                "--------------------------------------------------------------------------\n";
        fout << result[2] << " ms\n";
        fout << "--------------------------------------------------------------------------\n";
        fout << "Combined : \n"
                "--------------------------------------------------------------------------\n";
        fout << result[3] << " ms\n";
        fout << "--------------------------------------------------------------------------\n";
    }
    else
    {
        std::cout << "Benchmark file can't be opened." << std::endl;
    }
    fout.close();
    std::cout << "OK." << std::endl;

    std::cerr << "End ot the test." << endl;
}

void App::insertionSort(Point* point_array, int n, bool printing)
{
    for(int i = 0; i < n; i++)
    {
        int j = i;
        while(j > 0 and point_array[j-1] > point_array[j])
        {
            std::swap(point_array[j], point_array[j-1]);
            j--;
        }
        if(printing) printArray(point_array, n);
    }
}

int App::partition(Point *point_array, int low, int high)
{
    Point pivot = point_array[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do
        {
            i++;
        } while (point_array[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do
        {
            j--;
        } while (point_array[j] > pivot);

        // If two pointers met.
        if (i >= j) return j;

        std::swap(point_array[i], point_array[j]);
    }
}

void App::quickSort(Point *point_array, int low, int high, int max_size, bool printing)
{
    if(low < high)
    {
        if(printing) printArray(point_array, max_size); // printing if turned on
        int pi = partition(point_array, low, high); // partition index
        quickSort(point_array, low, pi, max_size, printing);
        quickSort(point_array, pi + 1, high, max_size, printing);
    }
}

void App::merge(Point *point_array, int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    //Create temp arrays
    Point* leftArray = new Point[subArrayOne];
    Point* rightArray = new Point[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = point_array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = point_array[mid + 1 + j];

    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            point_array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            point_array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        point_array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        point_array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void App::mergeSort(Point *point_array, int begin, int end, int max_size, bool printing)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(point_array, begin, mid, max_size);
    mergeSort(point_array, mid + 1, end, max_size);
    merge(point_array, begin, mid, end);

    if(printing) printArray(point_array, max_size);
}

void App::combinedSort(Point* point_array, int begin, int end, unsigned threshold, int max_size, bool printing)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;

    if(end - begin >= threshold)
    {
        mergeSort(point_array, begin, mid, max_size, printing);
        mergeSort(point_array, mid + 1, end, max_size, printing);
        merge(point_array, begin, mid, end);
    }
    else
    {
        insertionSort(point_array, end - begin + 1, printing);
    }

    if(printing) printArray(point_array, max_size);
}

void App::printArray(Point *point_array, int n)
{
    for(int k = 0; k < n; k++)
    {
        cout << point_array[k] << ' ';
    }
    cout << endl;
}

short App::choice(const char* criteria, short choice_amount, const char* variant, ...)
{
    const char** ptr = &variant;
    // Printing variants :
    std::cout << criteria << " : \n";
    for (short i = 1; i<=choice_amount; i++)
    {
        std::cout << i << " - " << *(ptr++) << '\n';
    }
    std::cout << "or type anything else to exit." << std::endl;
    // Entering choice :
    short chs = 0;
    std::cin>>chs;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Processing input :
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        chs = 0;
    }
    std::cout << std::endl;
    // Returning result :
    return chs;
}

int binpow(int x, int y)
{
    if(x == 0) return 0;
    if(y == 0) return 1;

    if(y%2) return x * binpow(x, y - 1);
    else
    {
        int b = binpow(x, y/2);
        return b*b;
    }
}