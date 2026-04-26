program flashinf
  implicit none
  character(len=100) :: line
  integer :: i, ios
  real :: x, y

  open(unit=10, file='flashinf.d', status='old', action='read')
  
  do
    read(10, '(A)', iostat=ios) line
    if (ios /= 0) exit
    
    read(line, *) x, y
    print *, 'Read values: ', x, y
  end do
  
  close(10)
end program flashinf