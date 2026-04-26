: show-cpu
  " /cpu" find-device
  " model" get-property
  if
    drop ." CPU: unknown" cr
  else
    ." CPU: " type cr
  then
;

: show-memory
  " /memory" find-device
  " reg" get-property
  if
    drop ." Memory: unknown" cr
  else
    ." Memory (raw): " . cr
  then
;

: sysinfo
  ." === System Info ===" cr
  show-cpu
  show-memory
;