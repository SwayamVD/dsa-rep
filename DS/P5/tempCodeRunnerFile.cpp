    void sortpoly(){
        Node* t = head;
        Node* t2 = head->next;
        while(t){
            while(t2){
                if(t2->exp > t->exp){
                    int c = t2->cof;
                    t2->cof = t->cof;
                    t->cof = c;

                    int e = t2->exp;
                    t2->exp = t->exp;
                    t->exp = e;

                }
                t2 = t2->next;
            }
            t = t->next;
        }
    }