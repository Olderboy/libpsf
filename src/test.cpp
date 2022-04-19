#include "psfinterface.h"
#include <unordered_map>

int main() {
    std::string dcopfile("../examples/data/opBegin");
    std::string pssfdfile("../examples/data/pss0.fd.pss");
    std::string tranfile("../examples/data/timeSweep");
    std::string srcsweepfile("../examples/data/srcSweep");
    //    PSFDataSet psftran(tranfile);
    //    PSFDataSet pssfd(pssfdfile);
    PSFParser pssop(dcopfile);
    // PSFDataSet srcsweep(srcsweepfile);
    // noisesummary();
    //pssop.get_signal_properties("XIRXRFMIXTRIM0.XRDAC4.XR.R1");
    
    // PSFDoubleScalar dd = 2.4;

    std::vector<std::string> sname = pssop.get_signal_names();
    //  sname = pssop.get_signal_names();
    std::unordered_map<std::string, PSFBaseData*> smap, *strc;
    for (auto i : sname) {
        smap[i] = dynamic_cast<PSFBaseData *>(pssop.get_signal(i));
    }

    for (auto i : smap) {
        std::cout << "name: " << i.first << " value: " << std::endl;
        ValueStruct* value = (ValueStruct*)i.second->ptr();
        for (auto j : *value) {
            std::cout << "(" << j.first << " : " << *j.second << ")" << std::endl; 
        }
    }
    return 0;
}