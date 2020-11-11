def solution(T):
  # Your solution goes here.
  
  T = T.replace(':', '')
  
  Inverted_T = T[::-1]
  valid_until_now = 1
  
  
  for i, value in enumerate(Inverted_T):
    
    if(Inverted_T[0] + Inverted_T[1] + Inverted_T[2] + Inverted_T[3] == "????"):
      valid_until_now *= 3*(10 + 4)*6*10
      break
      
    if value == '?':
      
   
      if i == 0:
        valid_until_now *= 10
        
      elif i == 1:
        if Inverted_T[i-1] != '?':
          valid_until_now *= 6 - int(Inverted_T[i-1])
          if Inverted_T[i+1] == '?':
            valid_until_now *= 10
        else:
          valid_until_now *= 6
          
      elif i == 2:
        if Inverted_T[i+1] == '2':
          valid_until_now *= 4
        elif Inverted_T[i-1] == '?':
          valid_until_now = valid_until_now
        elif Inverted_T[i-1] != '?':
          valid_until_now *= 10 - int(Inverted_T[i-1])
          
      elif i == 3:
          if int(Inverted_T[i-1]) <= 3:
            valid_until_now *= 3
          elif int(Inverted_T[i-1]) > 3:
            valid_until_now *= 2
            
          if Inverted_T[i-1] != '?':
            valid_until_now = valid_until_now
          else:
            valid_until_now *= 10 - int(Inverted_T[i-1])
    
    # This means no changes were made, therefore 0 possibilities        
    elif valid_until_now == 1 and i == 3:
      valid_until_now = 0
  
  #if conditions are not met
  if valid_until_now == None:
    return 0
  
  return valid_until_now
