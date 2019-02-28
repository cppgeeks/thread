
#include "Generator.hpp"
#include "Printer.hpp" 

int main(int argc, char ** argv){

    Generator* m_gen = new Generator() ;

    Printer* m_printer = new Printer();

    for (int i = 0; i < 100; i++){

            m_gen->Run();

            m_printer->Run(m_gen);
            
    }

    return 0;

}