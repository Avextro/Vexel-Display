import { createContext, useContext } from "react";
import { lightTheme } from "./lightTheme";

const ThemeContext = createContext(lightTheme);

export function AppThemeProvider({ children }: { children: React.ReactNode }) {
  return (
    <ThemeContext.Provider value={lightTheme}>{children}</ThemeContext.Provider>
  );
}

export function useTheme() {
  return useContext(ThemeContext);
}
