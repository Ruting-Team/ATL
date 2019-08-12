//
//  TransitionSystem.hpp
//  ATL 
//
//  Created by Jinlong He on 2019/8/12.
//  Copyright © 2019年 Ruting-Team. All rights reserved.
//

#ifndef TransitionSystem_hpp
#define TransitionSystem_hpp

#include "boost/graph/adjacency_list.hpp"
using namespace boost;

namespace atl {
    template <class StateProperty = bool, class TransitionProperty = char>
    class TransitionSystem : public adjacency_list<listS, vecS, bidirectionalS, StateProperty, TransitionProperty> {
    protected:
    public:
    };
}
#endif /* TransitionSystem_hpp */
