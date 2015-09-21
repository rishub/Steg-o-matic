//// We have not yet produced the test driver main routine for you.
//
//#include "provided.h"
//#include <iostream>
//using namespace std;
//
//
//
//int main()
//{
//	cout << "Test driver not yet written." << endl;
//
//    string str="AAAAAAAAAB";
//    vector<unsigned short> numbers;
//    //Compressor::compress
//    //Compressor::decompress
//
//    Compressor::compress(str,numbers);
//
//    cout << "Compression is done. Values = ";
//    for(unsigned int i=0;i<numbers.size();i++)
//        cout << " " << numbers[i];
//    cout << endl;
//
//
//    vector<unsigned short> v = {65, 65, 256, 65, 257, 65, 66, 517};
//    string s = "";
//    Compressor::decompress(v,s);
//    cout << s;
//
//
//    string hostIn = "<html>   \nQ \tQQ \t \nBBB\t\t\t   \n\nGG \r\nBBB \n\t\nDDD\nEEE </html>   ";
//    string hostOut = "";
//    Steg::hide(hostIn, "hidden message", hostOut);
//    cout << hostOut;
//
//    string s = "";
//    if(!Steg::reveal(hostOut,s))
//        cout << "error" << endl;
//    cout << s;
//
//
//	 string text;
//	 if ( ! WebSteg::hideMessageInPage("http://cs.ucla.edu", "Hello there!", text))
//		cout << "Error hiding!" << endl;
//	string msg;
//	if ( ! WebSteg::revealMessageInPage("http://cs.ucla.edu", msg))
//      cout << "Error revealing!" << endl;
//}

#include "HashTable.h"
#include "provided.h"
#include "http.h"
#include <iostream>
using namespace std;

int main()
{
    string originalPageText =
    "<html>\n"
    "<head>\n"
    " <title>My Pretend Web Page</title>\n"
    "</head>\n"
    "<body>\n"
    "<h2>My Pretend Web Page<h1>\n"
    "<p>\n"
    "I wish I were creative enough to have something interesting \n"
    "to say here.  I'm not, though, so this is a boring page.\n"
    "</p>\n"
    "<p>\n"
    "Oh, well.\n"
    "</p>\n"
    "</body>\n"
    "</html>\n"
    ;
    HTTP().set("http://boring.com", originalPageText);
    string plan =
    "Lefty and Mugsy enter the bank by the back door.\n"
    "Shorty waits out front in the getaway car.\n"
    "Don't let the teller trip the silent alarm.\n"
    ;
    string newPageText;
    if ( ! WebSteg::hideMessageInPage("http://boring.com", plan, newPageText))
    {
        cout << "Error hiding!" << endl;
        return 1;
    }
    
    HTTP().set("http://boring.com", newPageText);
    string msg;
    if ( ! WebSteg::revealMessageInPage("http://boring.com", msg))
    {
        cout << "Error revealing!" << endl;
        return 1;
    }
    if (msg != plan)
    {
        cout << "Message not recovered properly:\n" << msg << endl << plan;
        return 1;
    }
    cout << "Recovered text is what was hidden:\n" << msg;
    
    
    HashTable<string, int> nameToAge(100, 200);
    nameToAge.set("Carey", 43);
    nameToAge.set("David", 97);
    nameToAge.set("Timothy", 43, true);
    nameToAge.set("Ivan", 28);
    nameToAge.set("Sally", 22);
    nameToAge.set("David", 55);
    nameToAge.touch("Carey");
    // let's discard the two least recently written items
    for (int k = 0; k < 2; k++)
    {
        string discardedName;
        int discardedAge;
        if (nameToAge.discard(discardedName,discardedAge))
            cout << "Discarded " << discardedName
            << " who was " << discardedAge
            << " years old.\n";
        else
            cout << "There are no items to discard!\n";
    }
    
    /*
     vector<unsigned short> v;
     v.push_back(1);
     v.push_back(5);
     // We use the :: operator below because encode() is a static
     // member function. You don't create a BinaryConverter object
     // to use encode(); instead, you call it using the class name.
     string hiddenMessage = BinaryConverter::encode(v);
     cout << hiddenMessage; // prints tabs and spaces
     
     v.clear();
     // Using the -/_ representation in this comment, the string
     // below contains _______________-_____________-_-
     string msg = "               \t             \t \t";
     if (BinaryConverter::decode(msg, v))
     {
     cout << "The vector has " << v.size() << " numbers:";
     for (int k = 0; k != v.size(); k++)
     cout << ' ' << v[k];
     cout << endl;
     }
     else
     cout << "The string has a bad character or a bad length.";
     */
    /*
     string str="AAAAAAAAAB";
     vector<unsigned short> numbers;
     //Compressor::compress
     //Compressor::decompress
     
     Compressor::compress(str,numbers);
     
     cout << "Compression is done. Values = ";
     for(unsigned int i=0;i<numbers.size();i++)
     cout << " " << numbers[i];
     cout << endl;
     
     string output="";
     Compressor::decompress(numbers,output);
     cout << "Decompression is done. Output is " << output << endl;
     */
    /*
     string str = "Hello World!";
     vector<unsigned short> numbers;
     Compressor::compress(str,numbers);
     string hiddenMessage = BinaryConverter::encode(numbers);
     
     vector<unsigned short> num;
     if(BinaryConverter::decode(hiddenMessage, num))
     {
     string original_msg;
     Compressor::decompress(num,original_msg);
     }
     */
    /*
     string page = "<html>   \nQ \tQQ \t \nBBB\t\t\t   \n\nGG \nBBB \n\t\nDDD\nEEE </html>   ";
     string msg = "Hello World!";
     string output;
     Steg::hide(page,msg,output);
     string msg2;
     if (Steg::reveal(output, msg2))
     {
     if (msg == msg2)
     cout << "Steg::hide() and Steg::reveal() are successfully done!" << endl;
     }
     */
    
    /*
     string msg = "This class is finally over!";
     string host;
     HTTP().set("http://a.com", "<html>   \nQ \tQQ \t \nBBB\t\t\t   \n\nGG \nBBB \n\t\nDDD\nEEE </html>   ");
     
     if(WebSteg::hideMessageInPage("http://a.com", msg, host) )
     {
     HTTP().set("http://a.com",host); // replace the original webpage by the new content
     string msg2;
     if(WebSteg::revealMessageInPage("http://a.com", msg2))
     {
     if(msg == msg2)
     cout << "Successfully hide and reveal message in pages!!\n" << msg << endl;
     else
     {
     cout << "Hidden message and revealed message do not match!!" << endl;
     cout << "Hidden message:   " << msg << endl;
     cout << "Revealed message: " << msg2 << endl;
     }
     }
     
     else
     cout << "Failed to reveal message in page!!" << endl;
     
     }
     
     else
     cout << "Failed to hide message in page!!" << endl;
     */
}


