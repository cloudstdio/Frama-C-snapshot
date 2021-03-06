(**************************************************************************)
(*                                                                        *)
(*  This file is part of Frama-C.                                         *)
(*                                                                        *)
(*  Copyright (C) 2007-2018                                               *)
(*    CEA (Commissariat à l'énergie atomique et aux énergies              *)
(*         alternatives)                                                  *)
(*                                                                        *)
(*  you can redistribute it and/or modify it under the terms of the GNU   *)
(*  Lesser General Public License as published by the Free Software       *)
(*  Foundation, version 2.1.                                              *)
(*                                                                        *)
(*  It is distributed in the hope that it will be useful,                 *)
(*  but WITHOUT ANY WARRANTY; without even the implied warranty of        *)
(*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *)
(*  GNU Lesser General Public License for more details.                   *)
(*                                                                        *)
(*  See the GNU Lesser General Public License version 2.1                 *)
(*  for more details (enclosed in the file licenses/LGPLv2.1).            *)
(*                                                                        *)
(**************************************************************************)

module DatatypeMessages =
  Datatype.Make_with_collections
    (struct
       include Datatype.Serializable_undefined
       open Log
       type t = event
       let name = "message"
       let reprs =
         [ { evt_kind = Failure;
             evt_plugin = "";
             evt_category = None;
             evt_source = None;
             evt_message = "" } ]
       let mem_project = Datatype.never_any_project
       let hash (e: event)= Hashtbl.hash e
       let compare (e1: event) e2 = Extlib.compare_basic e1 e2
       let equal = Datatype.from_compare
     end)

module Messages =
  State_builder.List_ref
    (DatatypeMessages)
    (struct
       let name = "Messages.message_table"
       let dependencies = [ Ast.self ]
     end)
let () = Ast.add_monotonic_state Messages.self

let add_message m =
  Messages.set (m :: Messages.get ());;

let nb_errors () =
  let n = ref 0 in
  Messages.iter (fun e ->
      match e.Log.evt_kind with
      | Log.Error -> incr n
      | _ -> ());
  !n

let nb_warnings () =
  let n = ref 0 in
  Messages.iter (fun e ->
      match e.Log.evt_kind with
      | Log.Warning -> incr n
      | _ -> ());
  !n

let nb_messages() = nb_errors() + nb_warnings();;

let self = Messages.self

let iter f = List.iter f (List.rev (Messages.get ()))
let dump_messages () = iter Log.echo

let () =
  Log.add_listener ~kind:[ Log.Error; Log.Warning ] add_message;
;;

module OnceTable = 
  State_builder.Hashtbl
    (DatatypeMessages.Hashtbl)
    (Datatype.Unit)
    (struct
      let size = 37
      let dependencies = [ Ast.self ]
      let name = "Messages.OnceTable"
     end)

let check_not_yet evt =
  if OnceTable.mem evt then false
  else begin
    OnceTable.add evt (); 
    true
  end

let () = Log.check_not_yet := check_not_yet

let reset_once_flag () = OnceTable.clear ()


(*
Local Variables:
compile-command: "make -C ../../.."
End:
*)
