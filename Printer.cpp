#include "Printer.hpp"
#include <iostream>
Printer::Printer() : m_thr_printer_out(){       
}

void Printer::Init(){
        
}
void Printer::Print(Generator* m_gen){

       m_gen->takeMutex();   

       std::cout << m_gen->takeNewInt() << std::endl;

       m_gen->setMutex();
       
}


void Printer::Run( Generator* m_gen){       

        m_thr_printer_out = std::thread(&Printer::Print,this,m_gen);

        // m_thr_printer_out.detach();

        std::this_thread::sleep_for(std::chrono::seconds(1));  
                          
}

Printer::~Printer(){

      if (m_thr_printer_out.joinable() ) m_thr_printer_out.join(); 
       
}