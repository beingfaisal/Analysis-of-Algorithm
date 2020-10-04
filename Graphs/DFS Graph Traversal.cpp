#include <iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
class vertex;
class neighbour;


class vertex
{
public:
    int entryTime;
    int finishTime;
    int progress; //if its unvisited then progress = -1,in progress then progress = 0, all done then progress = 0 
    char letter;
    vertex* nextVert;
    neighbour* adjNei;
    vertex()
    {
        letter = '\0';
        nextVert = NULL;
        adjNei = NULL;
        entryTime = finishTime = progress = -1;
    }
    vertex(char &a)
    {
        letter = a;
        nextVert = NULL;
        adjNei = NULL;
        entryTime = finishTime = progress = -1;
    }
};

class neighbour
{

public:
    vertex* orgVertex;
    neighbour* nextNeigh;
    neighbour()
    {
        orgVertex = NULL;
        nextNeigh = NULL;
    }
};

class graph
{
public:
    vertex* startVertex;
    int totalVertx;
    graph()
    {
        startVertex = NULL;
        totalVertx = 0;
    }

    graph& addVertex(vertex *& v1)
    {
        if (startVertex ==  NULL)
        {
            startVertex = v1;
        }
        else
        {
            vertex* ptr;
            ptr = startVertex;
            while (ptr->nextVert)
            {
                ptr = ptr->nextVert;
            }
            ptr->nextVert = v1;
        }
        v1->nextVert = NULL;
        v1 = NULL;
        totalVertx++;
        return *this;
    }
    
    void addEdge(char src, char dest)
    {
        vertex* srcPtr;
        srcPtr = startVertex;
        bool srcFound = false;
        bool destFound = false;
        while (srcPtr && !srcFound)
        {
            if (srcPtr->letter == src)
            {
                srcFound = true;
            }
            else
            {
                srcPtr = srcPtr->nextVert;
            } 

        }
        if (!srcFound)
        {
            cout << "elemet " << src << "  Not Found" << endl;
            return;
        }
        else
        {
            vertex* destPtr;
            destPtr = startVertex;
            while (!destFound && destPtr)
            {
                if (destPtr->letter == dest)
                {
                    destFound = true;
                }
                else
                {
                    destPtr = destPtr->nextVert;
                }
            }


            if (!destFound)
            {
                cout << "elemet " << dest << "  Not Found" << endl;
                return;
            }
            else
            {
                neighbour* n1 = new neighbour();
                n1->orgVertex = destPtr;
                n1->nextNeigh = NULL;
                
                if (!srcPtr->adjNei)
                {
                    srcPtr->adjNei = n1;
                }
                else
                {
                    neighbour* temp1; //using this to find the end of neighbours list
                    temp1 = srcPtr->adjNei;
                    while (temp1->nextNeigh)
                    {
                        temp1 = temp1->nextNeigh;
                    }
                    temp1->nextNeigh = n1;

                }
                
                neighbour* n2 = new neighbour();
                n2->orgVertex = srcPtr;
                n2->nextNeigh = NULL;

                if (destPtr->adjNei == NULL)
                {
                    destPtr->adjNei = n2;
                }
                else
                {
                    neighbour* temp2;
                    temp2 = destPtr->adjNei;
                    while (temp2->nextNeigh)
                    {
                        temp2 = temp2->nextNeigh;
                    }
                    temp2->nextNeigh = n2;
                }                
            }

        }
    }

    void printVertex()
    {
        vertex *temp;
        temp = startVertex;
        while (temp != NULL)
        {
            cout << temp->letter << " " << endl;
            temp = temp->nextVert;
        }
    }

    void printNeigh_Vertex(char a, bool printEdges)
    {
        neighbour* nTemp;
        vertex* vTemp;
        vTemp = startVertex;
        bool vertFound = false;
        while (vTemp && !vertFound)
        {
            if (vTemp->letter == a)
            {
                vertFound = true;
            }
            else vTemp = vTemp->nextVert;
        }
        if (vertFound && !printEdges) //if you want to print neighbours the printEdges = false;
        {
            
            nTemp = vTemp->adjNei;
            cout << "neighbours of " <<a<<" are " <<endl;
            while (nTemp)
            {
                cout << nTemp->orgVertex->letter << " ";
                nTemp = nTemp->nextNeigh;
            }
            cout << endl;
        }
        else if (vertFound && printEdges) //if you want to print Edges the printEdges = true;
        {
            nTemp = vTemp->adjNei;
            cout << "The edges of "<<a<<" are  ";
            while (nTemp)
            {
                cout << "(" << a << ", " << nTemp->orgVertex->letter << ")   ";
                nTemp = nTemp->nextNeigh;
            }
            cout << endl;
        }
        else
        {
            cout << "the element you searched " << a << " has not found" << endl;
        }
        
    }

    void printAllEdges()
    {
        vertex* temp;
        temp = startVertex;
        while (temp)
        {
            printNeigh_Vertex(temp->letter, true);
            temp = temp->nextVert;
        }
    }
 

};

int DFS(vertex*& v1, int currentTime)
{
    cout << v1->letter <<"   "<< endl;
    v1->entryTime = currentTime;
    currentTime++;
    v1->progress = 0;//to set its progress to in progress
    neighbour* ptr;
    ptr = v1->adjNei;

    while (ptr != NULL)
    {
        if (ptr->orgVertex->progress == -1)
        {
            currentTime = DFS(ptr->orgVertex, currentTime);
            currentTime++;
        }
        ptr = ptr->nextNeigh;
    }
    v1->finishTime = currentTime;
    v1->progress = 1;
    return currentTime;


}




int stringConverter(char n)
{
    int newNum = -1;
    if ((n >= '0') && (n <= '9'))
    {
        newNum = n - '0';
    }
    return newNum;
}



