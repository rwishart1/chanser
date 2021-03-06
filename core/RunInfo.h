//////////////////////////////////////////////////////////////
///
///Class:		
///Description:
///
#pragma once

#include "BaseRunInfo.h"
#include "clas12reader.h"
#include <Rtypes.h>

namespace chanser{

  class RunInfo : public BaseRunInfo{

  public :
    
    void SetCLAS12(clas12::clas12reader* c12){_c12=c12;}
    clas12::clas12reader* CLAS12(){return _c12;}
    
  private :
    
    clas12::clas12reader* _c12={nullptr};
 
           
  };//class RunInfo
}
