#include <iostream>
#include <vector>

// Max Heap
class Heap {
private:
    std::vector<int> m_heapTree;
    
public:
    Heap() { m_heapTree.resize(1); }
    
    Heap (int data) {
        Heap();
        insert(data);
    }
    Heap (const std::vector<int> &dataArray) {
        Heap();
        insertArray(dataArray);
    }
    
    void printHeapTree ();
    void insert (int data);
    void insertArray (const std::vector<int> &dataArray);
    void insertHapify (const std::vector<int> &dataArray);
    void deleteRoot ();
    
    ~Heap() {}
};

void Heap::printHeapTree() {
    
    for(int i(1); i < m_heapTree.size(); ++i) {
        std::cout << m_heapTree.at(i) << ' ';
    }
    std::cout << std::endl;
}

void Heap::insert (int data) {
    
    m_heapTree.push_back(data);
    
    if (m_heapTree.size() == 2) {
        return;
    }
    else {
        
        int i = (int)m_heapTree.size() - 1;
        int dataToSort = m_heapTree.at(i);
        
        while (i > 1 && m_heapTree.at(i) > m_heapTree.at(i/2)) {
            
            m_heapTree.at(i) = m_heapTree.at(i/2);
            i = i/2;
        }
        m_heapTree.at(i) = dataToSort;
    }
}

void Heap::insertArray (const std::vector<int> &dataArray) {
    
    for (int i(0); i < dataArray.size(); ++i) {
        this->insert(dataArray.at(i));
    }
}

void Heap::insertHapify (const std::vector<int> &dataArray) {
    
    for (const auto &el: dataArray) {
        m_heapTree.push_back(el);
    }
    
    int arrSize = int(m_heapTree.size());
    
    for (int last(arrSize - 1), curr(last); last >= 0; --last) {
        
        while (curr * 2 < arrSize - 1) {
            
            if (m_heapTree.at(curr) < m_heapTree.at(curr * 2)) {
                
                if(m_heapTree.at(curr * 2) > m_heapTree.at(curr * 2 + 1)) {
                    
                    std::swap(m_heapTree.at(curr), m_heapTree.at(curr * 2));
                    curr = curr * 2;
                }
                else {
                    std::swap(m_heapTree.at(curr), m_heapTree.at(curr * 2 + 1));
                    curr = curr * 2 + 1;
                }
            }
        }
        curr = last;
    }
}

void Heap::deleteRoot () {
    
    int curr (1);
    int child (curr * 2);
    int arrSize = int(m_heapTree.size());
    
    m_heapTree.at(1) = m_heapTree.at(arrSize - 1);
    while (child < arrSize - 1) {
        
        if (m_heapTree.at(child + 1) > m_heapTree.at(child)) {
            child++;
        }
        if (m_heapTree.at(curr) < m_heapTree.at(child)) {
            std::swap(m_heapTree.at(curr), m_heapTree.at(child));
            curr = child;
            child *= 2;
        }
        else { break; }
    }
}
