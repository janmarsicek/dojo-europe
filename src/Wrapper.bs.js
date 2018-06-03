// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Fetcher$MyProjectName = require("./Fetcher.bs.js");

var component = ReasonReact.reducerComponent("Wrapper");

function make(render, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              Curry._1(self[/* send */3], /* Loading */Block.__(1, [true]));
              return Fetcher$MyProjectName.fetchGet("https://immense-river-25513.herokuapp.com/locations", (function (data) {
                            return Curry._1(self[/* send */3], /* Loaded */Block.__(0, [data]));
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var match = param[/* state */1];
              var markers = match[/* markers */1];
              var foo = match[/* loading */0] ? "Loading..." : (
                  markers.length !== 0 ? "Loaded" : "Loaded, no results"
                );
              return React.createElement("div", undefined, React.createElement("h2", undefined, foo), Curry._1(render, $$Array.map((function (item) {
                                    var match = item.location;
                                    return {
                                            markerOffset: -25,
                                            name: item.username,
                                            coordinates: /* tuple */[
                                              match[1],
                                              match[0]
                                            ]
                                          };
                                  }), markers)));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* loading */false,
                      /* markers : array */[]
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                return /* Update */Block.__(0, [/* record */[
                            /* loading */action[0],
                            /* markers */state[/* markers */1]
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* loading */false,
                            /* markers */action[0]
                          ]]);
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
