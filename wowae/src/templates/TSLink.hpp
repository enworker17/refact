//
// TSLink.hpp -  template TSLink
//

#pragma once

template<typename T>
class TSLink
{
private:
    TSLink<T>*  m_prevlink;
    T* 		    m_next;


    void  Constructor() {
        return;
    }

    void  CopyConstructor(const TSLink<T>&) {
        return;
    }


public:
    TSLink<T>() { 
        Constructor(); 
    }

    ~TSLink<T>() { 
        return;
    }
    
    TSLink<T>(const TSLink<T>& source) { 
        CopyConstructor(source); 
    }

    TSLink<T>&  operator=(const TSLink<T>& source) { 
        CopyConstructor(source); 
        return this; 
    }
    
    TSLink<T>* NextLink(int linkoffset) { 
        return nullptr; 
    }

    void Unlink() { 
        return;
    }

    bool IsLinked() { 
        return false; 
    }
    
    T* Next() { 
        return nullptr; 
    }

    T* Prev() { 
        return nullptr; 
    }

    T* RawNext() {
        return nullptr; 
    }
    
    const T* Next() const { return nullptr; }
    const T* Prev() const { return nullptr; }
    const T* RawNext() const { return nullptr; }

};

