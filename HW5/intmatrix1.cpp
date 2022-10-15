//
// Created by yy on 2022/10/13.
//

#include "intmatrix1.h"

//void intmatrix1::setRow(int a) {
//    this->row= a;
//}
//
//void intmatrix1::setCol(int a) {
//    this->col= a;
//}
//
//int intmatrix1::getCol(int a) {
//    return col;
//}
//
//int intmatrix1::getRow(int a) {
//    return this->row;
//}

void intmatrix1::init(const char* as){
    int n = strlen(as);
    int count = 0;
    int local_col = 0;
    int local_row = 0;
    bool isValid = true;

    // pick the value of local_row and local_col.
    for(int i=0; i<n; i++) {
        if(as[i] == '|' || i == n-1) {
            local_row++;
            if(local_col == 0 ) {
                local_col = count;
                if(i == n-1 && as[i]>='0' && as[i]<='9' && !(as[i-1]>='0' && as[i-1]<='9')) {
                    local_col++;
                }
            }
            else {
                if(i == n-1 && as[i]>='0' && as[i]<='9' && !(as[i-1]>='0' && as[i-1]<='9')) {
                    count++;
                }
                if(count != local_col) {
                    isValid = false;
                }
            }
            count = 0;
        }
        else if(as[i] == ' ') {
            continue;
        }
        else {
            if(i!=0) {
                if(as[i-1]>='0' && as[i-1]<='9') {
                    continue;
                }
            }
            count++;
        }
    }

// create new matrix.
    if(!isValid) {
        pointer = nullptr;
        pCol = 0;
        pRow = 0;
        return;
    } else {
        this->pRow = local_row;
        this->pCol = local_col;
        pointer = new int*[local_row];
        for(int i =0; i < local_row; i++) {
            pointer[i] = new int[local_col];
        }
    }

// put the value into matrix.
    int r=0;
    int c = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        if(as[i] == '|') {
            r++;
            c = 0;
        }
        else if(as[i] == ' ') {
            continue;
        }
        else {
            if(i == n-1) {
                sum = sum*10+(as[i]-'0');
                pointer[r][c] = sum;
                break;
            }
            if(as[i+1] == ' ' || as[i+1] == '|') {
                sum = sum*10+(as[i]-'0');
                pointer[r][c] = sum;
                sum = 0;
                c++;
            }
            else {
                sum = sum*10+(as[i]-'0');
            }

        }
    }

}

void intmatrix1::init(int row, int col ) {
    pRow = row;
    pCol = col;
    pointer = new int*[row];
    for(int i=0; i<row; i++) {
        pointer[i] = new int[col];
    }

}

void intmatrix1::init(int row, int col, int value) {
    pRow = row;
    pCol = col;
    pointer = new int*[row];
    for(int i=0; i<row; i++) {
        pointer[i] = new int[col];
        for(int j=0; j<col; j++) {
            pointer[i][j] = value;
        }
    }

}

void intmatrix1::init() {
    this->pointer = nullptr;
}

void intmatrix1::print(const char* str) {
    cout<< "----" << str << "----" << endl;
    if(pointer == nullptr || pRow == 0 || pCol == 0) {
        cout << "  Empty Matrix" << endl;
    }
    else {
        for(int i=0; i<pRow; i++) {
            for(int j=0; j<pCol; j++) {
                cout<< pointer[i][j] << " ";
                if(j == pCol-1) {
                    cout<< endl;
                }
            }
        }
    }
}

intmatrix1 intmatrix1::add(intmatrix1 a) {
    int compRow = a.pRow;
    int compCol = a.pCol;
    intmatrix1 ab;
    ab.init();
    if(pRow != compRow || pCol != compCol) return ab;
    ab.init(pRow,pCol);

    for(int i=0; i<pRow; i++) {
        for(int j=0; j<pCol; j++) {
            ab.pointer[i][j] = pointer[i][j]+a.pointer[i][j];
        }
    }
    return ab;

}

intmatrix1 intmatrix1::mult(intmatrix1 a) {
    int compRow = a.pRow;
    int compCol = a.pCol;
    intmatrix1 c;
    c.init();
    if(pCol != compRow) return c;
    c.init(pRow,compCol);

    for(int i=0; i<pRow; i++) {
        for(int j =0; j<compCol; j++) {
            int sum = 0;
            for(int k=0; k<pCol; k++) {
                sum += pointer[i][k]*a.pointer[k][j];
            }
            c.pointer[i][j] = sum;
        }
    }
    return c;


}

void intmatrix1::fini() {
    for(int i=0; i<pRow; i++) {
        delete [] pointer[i];
    }
    delete pointer;
}

bool intmatrix1::isEmpty() {
    if(pRow == 0 || pCol == 0) return true;
    return false;
}

bool intmatrix1::isEqual(intmatrix1 s) {
    int compRow = s.getRow();
    int compCol = s.getCol();
    if(pRow != compRow || pCol != compCol) return false;
    int** curpointer = s.getPointer();
    for(int i=0; i<pRow; i++) {
        for(int j=0; j<pCol; j++) {
            if(pointer[i][j] != curpointer[i][j]) {
            return false;
            }
        }

    }
    return true;

}

int intmatrix1::getRow() {
    return this->pRow;
}

int intmatrix1::getCol() {
    return pCol;
}

int** intmatrix1::getPointer() {
    return pointer;
}