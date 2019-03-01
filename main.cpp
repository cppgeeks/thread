
#include "Generator.hpp"
#include "Printer.hpp" 

int main(int argc, char ** argv){

    Generator* m_gen = new Generator();

    Printer* m_printer = new Printer();

    while(true){

            m_gen->Run();

            m_printer->Run(m_gen);
            
    }

    return 0;

}