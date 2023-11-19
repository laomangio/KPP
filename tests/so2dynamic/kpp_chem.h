
/*! Set variable species concentration. */
#define SET_VAR(ind_spec, qnt_Cspec, M) 			\
  if (ctl->qnt_Cspec >= 0)					\
    VAR[ind_spec] = atm->q[ctl->qnt_Cspec][ip] * M;

/*! Get variable species concentration. */
#define GET_VAR(ind_spec, qnt_index, M)			\
  if (qnt_index >= 0)					\
    atm->q[qnt_index][ip] = VAR[ind_spec] / M;

/*! Initialize concentration quantity. */
#define INIT_CQNT(qnt_index, clim_zm_t)					\
  if (qnt_index >= 0)							\
    atm->q[qnt_index][ip] =						\
      clim_zm(&clim_var_t, atm->time[ip], atm->lat[ip], atm->p[ip]);

/*! Initialize KPP chemistry. */
void kpp_chem_initialize(
  ctl_t * ctl,
  clim_t * clim,
  met_t * met0,
  met_t * met1,
  atm_t * atm,
  double *VAR,
  int ip);

/*! Save KPP results. */
void kpp_chem_output2atm(
  atm_t * atm,
  ctl_t * ctl,
  met_t * met0,
	met_t * met1,
  double *VAR,
  int ip);

/*! KPP integration function. */
void INTEGRATE(
  double TIN,
  double TOUT);

int Rosenbrock(double Y[], double Tstart, double Tend,
   double AbsTol[], double RelTol[],
   void (*ode_Fun)(double, double [], double []), 
   void (*ode_Jac)(double, double [], double []),
   double RPAR[], int IPAR[]);

void FunTemplate( double T, double Y[], double Ydot[] );
void JacTemplate( double T, double Y[], double Ydot[] );