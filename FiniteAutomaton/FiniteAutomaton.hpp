//
//  FiniteAutomaton.hpp
//  ATL 
//
//  Created by Jinlong He on 2019/8/12.
//  Copyright © 2019年 Ruting-Team. All rights reserved.
//

#ifndef FiniteAutomaton_hpp
#define FiniteAutomaton_hpp
#include <unordered_map>
#include <unordered_set>
#include "boost/graph/adjacency_list.hpp"
using namespace boost;

namespace atl {
    template <class StateProperty = bool, class LabelProperty = char>
    class FiniteAutomaton : public adjacency_list<listS, vecS, bidirectionalS, StateProperty, LabelProperty> {
        typedef unordered_set<StateProperty> StateProperties;
        typedef unordered_set<LabelProperty> LabelProperties;
        typedef typename graph_traits<FiniteAutomaton<StateProperty, LabelProperty>>::vertex_descriptor State;
        typedef typename graph_traits<FiniteAutomaton<StateProperty, LabelProperty>>::edge_descriptor Transition;
        typedef unordered_set<State> States;
        typedef property_map<FiniteAutomaton<StateProperty, LabelProperty>, StateProperty> StatePropertyMap;
    protected:
        State initialState;
        States finalStates;
        LabelProperties labelProps;
        StateProperties stateProps;
    public:
        /// \brief Adds a State with @param prop in this class.
        /// \param prop The property of this State.
        /// \return State.
        State addState(const StateProperty& prop) {
            return add_vertex(prop, *this);
        }

        /// \brief Adds a Transition from @param source to @param target with @param prop in this class.
        /// \param source The source State.
        /// \param source The target State.
        /// \param prop The property of this Transition.
        /// \return Boolean.
        bool addTransition(State source, State target, const LabelProperty& prop) {
            return add_edge(source, target, prop, *this).second;
        }
    };
}
#endif /* FiniteAutomaton_hpp */
